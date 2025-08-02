#include <iostream>

int main() {

    std::string s1 = "a really looooong string....";

    // This has to do a complete copy of all chars from s1
    // to s2
    std::string s2 = s1;

    // How do move semantics help?

    std::string s3;

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s3: " << s3 << std::endl;

    // std::move allows us to 'adopt' or 'steal' the value
    s3 = std::move(s1);

    // We can more explicitly call the static_cast here
    // to move value of s1 to s3
    // s3 = static_cast<std::string&&>(s1);

    std::cout << "s3 after move: " << s3 << std::endl;

    // IMP: s1 is still a "valid" value
    // It can store a nullptr but it is still valid string
    std::cout << "s1 after move: " << s1 << std::endl;

    return 0;
}