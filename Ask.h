/**
    File    : Ask.h
    Author  : Menashe Rosemberg
    Created : 2017.12.03            Version: 20190305.1

    Construct a simple question and wait the answer

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef ASK_H
#define ASK_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define ASK_YESorNO     {"no", "yes"}

namespace ASK {
          constexpr uint8_t YESorNO_BEHAVIOR        = 0b00000010;
          constexpr uint8_t DEFAULT_BEHAVIOR        = 0b00000010;

          constexpr uint8_t SHOW_IS_CASE_IN_LOOP    = 0b00000000;
          constexpr uint8_t NOT_SHOW_ANSWERS        = 0b00000001;
          constexpr uint8_t IS_NOT_CASESENS         = 0b00000010;
          constexpr uint8_t NOT_IN_LOOP             = 0b00000100;   //wasmade() function member will returns 255 if the answare gave isn't in Answers

          constexpr uint8_t ANSWARE_BY_LETTERS      = 0b00001000;

}

struct Ask : public ostream {
       Ask();
       Ask(const string& sTheQuestion);
       Ask(vector<string>&& aAns, uint8_t iOptions = ASK::SHOW_IS_CASE_IN_LOOP);
       Ask(const string& sTheQuestion, vector<string>&& aAns, uint8_t iOptions = ASK::SHOW_IS_CASE_IN_LOOP);
      ~Ask() = default;

    void hastheAnswers(vector<string>&& aAns);                //Set vector with questions: {"Don't", "Do it"}
    void hastheBehavior(uint8_t iOptions);                  //use the logic '|' to set behavior: ASK::NOT_SHOW_ANSWERS | ASK::NOT_IN_LOOP
//    void AnotherQuestion();                                 //Reset the class to be ready to another question

    uint8_t wasmade();                                      //Make the question.

    private:
        stringbuf sstheQuestionIs;
        vector<string> Answers = ASK_YESorNO;
        uint8_t iBehavior = ASK::SHOW_IS_CASE_IN_LOOP;

        Ask(const Ask&) = delete;
        Ask& operator=(const Ask&) = delete;
};
/*
uint8_t Ask(const string& sQuestion,
                  const vector<string>& aAnswers,
                  uint8_t iOption =    ASK::SHOW_ANSWERS);
*/
#endif // ASK_H
