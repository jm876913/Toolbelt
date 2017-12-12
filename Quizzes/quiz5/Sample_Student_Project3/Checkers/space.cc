//
//  space.cpp
//  
//
//  Created by Michael Boyd on 4/13/15.
//
//

#include "space.h"
namespace main_savitch_14
{
    void space::remove_piece()
    {
        if (this->is_red()) {
            this->set_red(false);
            this->set_occ(false);
        }
        else if (this->is_black()) {
            this->set_black(false);
            this->set_occ(false);
        }
    }
    
    void space::place_red()
    {
        this->set_red(true);
        this->set_occ(true);
    }
    
    void space::place_black()
    {
        this->set_black(true);
        this->set_occ(true);
    }

}