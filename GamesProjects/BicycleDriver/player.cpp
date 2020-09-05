#include "player.h"
#include <string>

int player::get_id()
{
    return id;
}

void player::set_id(int iit)
{
    id = iit;
}

std::string player::get_nickname()
{
    return nickname;
}

void player::set_nickname(string nickn)
{
    nickname = nickn;
}

int player::get_score()
{
    return score;
}

void player::set_score(int sc)
{
    score = sc;
}
