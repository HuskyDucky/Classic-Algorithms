/**
    File    : Ask.cpp
    Author  : Menashe Rosemberg
    Created : 2017.12.03            Version: 20181111.3

    Construct a simple question and wait the answer

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Ask.h"

Ask::Ask() : ostream(&this->ssTheQuestionIs) {}

Ask::Ask(vector<string>&& aAns, uint8_t iOptions)
        : ostream(&this->ssTheQuestionIs), Answers(aAns), iBehavior(iOptions) {}

Ask::Ask(const string& TheQuestion)
        : ostream(&this->ssTheQuestionIs) {
        ssTheQuestionIs.sputn(TheQuestion.c_str(), TheQuestion.size());
}

Ask::Ask(const string& TheQuestion, vector<string>&& aAns, uint8_t iOptions)
        : ostream(&this->ssTheQuestionIs), Answers(aAns), iBehavior(iOptions) {
        ssTheQuestionIs.sputn(TheQuestion.c_str(), TheQuestion.size());
}

void Ask::hastheAnswers(vector<string>& aAns) {
     this->Answers = aAns;
}

void Ask::hastheBehavior(uint8_t iOptions) {
     this->iBehavior = iOptions;
}

/*void Ask::AnotherQuestion() {
     this->Answers = {};
     this->iBehavior = ASK::SHOW_ANSWERS;
     this->ssTheQuestionIs.str("");
}*/

struct Ask::GenLetter {
       char letter() {
            switch (Letter) {
                case 123: return (65);
                case  91: return (48);
                case  58: return '*';
                default: if (Letter != '*')
                            ++Letter;
            }

            return Letter;
        }
    private:
        char Letter = 96;
};

uint8_t Ask::wasmade() {

        if (this->iBehavior & ASK::ANSWARE_BY_LETTERS) {
            GenLetter Next;

            for (auto& IIt : this->Answers)
                if (IIt.compare(1, 2, "- ") != 0) {
                    IIt.insert(0, " - ");
                    IIt[0] = Next.letter();
                }
        }

        for (;;) {
            cout << this->ssTheQuestionIs.str();

            if (!(this->iBehavior & ASK::NOT_SHOW_ANSWERS))
                for (auto& IIt : this->Answers)
                    cout << "\n\t[" << IIt << ']';

            cout << "\n: ";

            string sAux;
            getline(cin, sAux);

            if (this->iBehavior & ASK::IS_NOT_CASESENS)
               transform(sAux.begin(), sAux.end(), sAux.begin(), ::tolower);

            if (this->iBehavior & ASK::ANSWARE_BY_LETTERS) {
               for (auto& IIt : this->Answers)
                   if (sAux[0] == IIt[0])
                      return sAux[0];

            } else {
                auto IIt = find(this->Answers.cbegin(), this->Answers.cend(), sAux);

                if (IIt != this->Answers.cend()) {
                   this->ssTheQuestionIs.str("");
                   return IIt - this->Answers.cbegin();
                }
            }

            if (this->iBehavior & ASK::NOT_IN_LOOP) {
               this->ssTheQuestionIs.str("");
               return 255;
            }

            cout << "\nIt is not an option.\n\n";
        }
}
