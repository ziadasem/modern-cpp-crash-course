[[noreturn]] void noReturnControlToTheCaller(){
    while(1){}
}

int func(int p){
    if (p  < 0){
        return 10 ;
    }
    noReturnControlToTheCaller();
}

int main(){
    return 0 ;
}