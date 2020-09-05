#ifndef BIKES_PLAYER_H
#define BIKES_PLAYER_H

#include <soci/soci.h>
#include <string>

using namespace std;

class player {
    int id; //it is autoincrement
    string nickname;
    int score;
public:
    int get_id();
    void set_id(int); // id is autoincrement!

    string get_nickname();
    void set_nickname(string);

    int get_score();
    void set_score(int);
};


namespace soci
{
    template<>
    struct type_conversion<player>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator /* ind */, player& p)
        {
            p.set_id(v.get<int>("ID"));
            p.set_nickname(v.get<std::string>("nickname"));
            p.set_score(v.get<int>("score", 0));

            // alternatively, the indicator can be tested directly:
            // if (v.indicator("GENDER") == i_null)
            // {
            //     p.gender = "unknown";
            // }
            // else
            // {
            //     p.gender = v.get<std::string>("GENDER");
            // }
        }

        static void to_base(player& p, values& v, indicator& ind)
        {
            //v.set("id", p.get_id());
            v.set("nickname", p.get_nickname());
            v.set("score", p.get_score());
            //ind = i_ok;
        }
    };
}
#endif