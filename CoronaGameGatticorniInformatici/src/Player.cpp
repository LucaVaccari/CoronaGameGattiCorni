#include "Player.h"

Player::Player() {}

extern bool inGame;

void Player::Start()
{
    m_lives = 7;
    m_score = 0;
    m_length = 7;
    m_pos.X = SCREEN_WIDTH / 2 - m_length / 2;
    m_pos.Y = SCREEN_HEIGHT - m_lives - 1;
    PrintPlayer();
    PrintLifeBars();
}

void Player::Update()
{
    if( Input::Get().IsPressed( VK_LEFT ) )
    {
        stepLeft();
    }
    if( Input::Get().IsPressed( VK_RIGHT ) )
    {
        stepRight();
    }
    PrintPlayer();
}

void Player::TakeDamage()
{
    m_lives--;
    PrintLifeBars();

    if( m_lives <= 0 )
    {
        EndGame();
    }
}

void Player::ScorePoint( const int &points )
{
    m_score += points;
}

Player& Player::Get()
{
    static Player s_instance;
    return s_instance;
}

void Player::stepLeft()
{
    if( m_pos.X > 0 )
    {
        m_pos.X--;
    }
}

void Player::stepRight()
{
    if( m_pos.X < SCREEN_WIDTH-m_length )
    {
        m_pos.X++;
    }
}

void Player::PrintPlayer()
{
    //Clear the line where the player is.
    Output::Get().FillChar( { 0, m_pos.Y }, { SCREEN_WIDTH, 1 }, ' ', BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    //Print the player in the new position.
    Output::Get().FillChar( m_pos, { m_length, 1 }, '=', FOREGROUND_WHITE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
}
void Player::PrintLifeBars()
{
    Output::Get().FillChar({ 0, SCREEN_HEIGHT - 7 },
    { SCREEN_WIDTH, 7 },
    ' ',
    BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    Output::Get().FillChar({ 0, SCREEN_HEIGHT - m_lives },
    { SCREEN_WIDTH, m_lives },
    '-',
    BACKGROUND_BLUE | BACKGROUND_INTENSITY |
    FOREGROUND_WHITE | FOREGROUND_INTENSITY);
}

void Player::EndGame()
{
    Output::Get().FillChar({ 0, 0 }, { SCREEN_WIDTH, SCREEN_HEIGHT }, ' ', BACKGROUND_POOP);
    inGame = false;
}
