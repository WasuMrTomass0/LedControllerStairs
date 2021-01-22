#pragma once

class NotCopyable {
private:
    // NotCopyable();
public:
    //NotCopyable(const NotCopyable&) = delete; // non construction-copyable
    //NotCopyable& operator=(const NotCopyable&) = delete; // non copyable
};
