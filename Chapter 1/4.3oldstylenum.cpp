enum class StrongEnum {
    A,
    B,
    C
};

enum class NonConflictingEnum {
    A,
    B,
    C
};

enum  OldEnum {
    AA,
    BB,
    CC
};

enum  ConflictingEnum {
    AA, //error: redefinition of enumerator 'AA'
    BB,
    CC
};

int main(){
    OldEnum oldEnum{AA};  //without qualifying parent enum
}