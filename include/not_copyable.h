#ifndef _NOT_COPYABLE_H_
#define _NOT_COPYABLE_H_

// This class bans the use of copy constructor & assignment operator.
// Any class that does not want to allow copy constructor & assignment operator
// should inherit the NotCopyable class.

class NotCopyable
{
    protected:
        NotCopyable() {}
        virtual ~NotCopyable() {}

    private:
    // Ban the use of assignment operator. 
        NotCopyable &
        operator =(
            const NotCopyable &NotImplemented
            );
    // Ban the copy constructor.
        NotCopyable(
            const NotCopyable &NotImplemented
            );

};

#endif // _NOT_COPYABLE_H_
