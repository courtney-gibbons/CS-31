#ifndef Die_h
#define Die_h

namespace cs31
{
    
// The purpose of this class is to provide random six-sided Die
class Die
{
public:
    Die( int sides = 6 ); // by default, a six sided die
    // change the value of the Die
    void roll();
    // trivial getter
    int  getValue( ) const;
    // trivial setter
    void setValue( int amount );  // cheating...
private:
    int  mSides;
    int  mValue;
};

    
}
#endif /* Die_h */
