#ifndef GUESSPASSWORD_H
#define GUESSPASSWORD_H

namespace GuessPass {
    struct Pass {
        int pass1{};
        int pass2{};
        int pass3{};
        int pass4{};
    };
}

void getPasswordStruct(GuessPass::Pass& pass) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 4);

    pass.pass1 = dis(gen);
    pass.pass2 = dis(gen);
    pass.pass3 = dis(gen);
    pass.pass4 = dis(gen);
}

#endif //GUESSPASSWORD_H
