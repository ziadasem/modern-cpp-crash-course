#include <optional>
#include <iostream>
std::optional<int> getValue(bool success){
    if (success){
        return 181;
    }
    return std::nullopt; // or {}

}
int main(){
    std::optional<int> withValue {getValue(true)};
    std::optional<int> withoutValue {getValue(false)};
    if (withValue){
         std::cout << "access value with method 1: "<< withValue.value()  << " \n";
        std::cout << "access value with method 2: "<< *withValue  << " \n";
    }
    if (withValue.has_value()) {
         std::cout << "access value with method 1: "<< withValue.value()  << " \n";
         std::cout << "access value with method 2: "<< *withValue  << " \n";
    }
   
   if (withoutValue){
         std::cout << "access value with method 1: "<< withoutValue.value()  << " \n";
        std::cout << "access value with method 2: "<< *withoutValue  << " \n";
    }
    if (withoutValue.has_value()) {
         std::cout << "access value with method 1: "<< withoutValue.value()  << " \n";
         std::cout << "access value with method 2: "<< *withoutValue  << " \n";
    }

    std::cout << "value is "<< withoutValue.value_or(-1)  << " \n";


}