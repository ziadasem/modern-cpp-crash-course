#include <iostream>
enum class AppState {
    Running = 5,
    Paused,
    Exiting
};

enum class ServerState {
    Running = 12,
    Paused,
    Exiting
};

int main(){
    //no conflict
    AppState appState{AppState::Running};
    ServerState serverState{ServerState::Running};

    std::cout <<static_cast<int>(appState)<<std::endl;
    std::cout <<static_cast<int>(serverState)<<std::endl;

    //same enumartor name, but different values and no conflicts

    //c++ > 20
    //using  class ServerState;
    //std::cout <<static_cast<int>(Running)<<std::endl; //12

    return 0;
}