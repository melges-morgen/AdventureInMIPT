//
//  GameObject.hpp
//  AdventureOnMIPT
//
//  Created by Морген Матвей on 02.05.16.
//
//

#ifndef GameObject_h
#define GameObject_h

#include <utility>
#include <set>

typedef std::pair<int, int> Position;

class GameObject
{
public:
    inline const Position & getBasicPosition() const noexcept
    {
        return basicPosition_;
    }
    
    inline const std::set<Position> & getPositionFigure() const noexcept
    {
        return positionFigure_;
    }

    
private:
    Position basicPosition_;
    std::set<Position> positionFigure_;
};

#endif /* GameObject_hpp */
