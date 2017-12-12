//
//  space.h
//
//
//  Created by Michael Boyd on 4/8/15.
//
//

#ifndef SPACE
#define SPACE

namespace main_savitch_14
{
    class space
    {
    public:
        space(){occ = false; king = false; black = false; red = false; jumped = false;}
        //accessors
        const bool is_occ()const {return occ;}
        const bool is_king()const {return king;}
        const bool is_black()const {return black;}
        const bool is_red()const {return red;}
        const bool was_jumped()const {return jumped;}
        
        //modifiers
        void set_occ(bool choice){occ = choice;}
        void set_king(bool choice){king = choice;}
        void set_black(bool choice){black = choice;}
        void set_red(bool choice){red = choice;}
        void set_jumped(bool choice){jumped = choice;}
        void remove_piece();
        void place_red();
        void place_black();
    private:
        bool occ, king, black, red, jumped;
    };
}

#endif