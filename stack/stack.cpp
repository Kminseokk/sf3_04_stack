#include <iostream>
#include <vector>
#include<string> //stoi 사용하기 위해 선언
#include <variant> // variant 사용하기 위해 선언

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> data;

public:
    // 스택에 요소를 추가하는 함수
    void push(const T& item) {
        data.push_back(item);
    }


    // 스택에서 요소를 제거하고 반환하는 함수
    T pop() { //T는 다양한 타입의 요소를 넣는 것.
        if (empty()) {
            throw runtime_error("스택이 비어 있습니다.");
            //여기로 올 수 없게 예외처리 해놓음.
        }
        T item = data.back();
        data.pop_back();
        return item;
    }

    // 스택이 비어 있는지 확인하는 함수
    bool empty() const {
        return data.empty();
    }

    // 스택의 크기를 반환하는 함수
    int size() const {
        return data.size();
    }

    // 스택의 요소를 맨 밑(bottom)부터 출력하는 함수
    void printFromBottom() const {
        for (int i = data.size() - 1; i >= 0; --i) {
            cout << i <<"번 원소: '" << data[i] << "'" << endl;
        }
    }

    // 스택의 가장 마지막 원소를 출력하는 함수
    void printLastElement() const {
        if (!empty()) {
            cout << data.back();
        }
        else {
            cout << "스택이 비어 있습니다." << endl;
        }
    }
};

//숫자인지 판별하는 클래스
class NumberChecker {
public:
    static bool IsNumeric(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Stack<int> myStack; 
    // variant을 사용하여 여러 타입의 데이터를 저장할 수 있도록 수정할수 있는거 같은데
    // 정확하게 선언할 수 있는 방법을 모르겠음.


    //사용자에게 입력받을 숬자
    string User_Choice;
    int int_User_Choice; 

    string User_input;

    //스택 숫자 세기
    int j;

    while (1) {
        // 스택의 크기 출력
        cout << "* ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
        cout << "* 현재 스택 크기: " << myStack.size() << endl;
        cout << "* 1. 스택에 숫자 넣기." << endl;
        cout << "* 2. 스택에 요소 제거(후입선출)" << endl;
        cout << "* 3. 현재 스택 요소 다 출력." << endl;
        cout << "* 4. 종료." << endl;
        cout << "* ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
        cout << "입력 : ";
        cin >> User_Choice;

        if (NumberChecker::IsNumeric(User_Choice)) {
            int_User_Choice = stoi(User_Choice);


            j = myStack.size(); //스택의 크기에 맞게 넣기
            cout << "\n";

            if (int_User_Choice == 1) {
                cout << j << "번째 스택에 원하는 숫자를 넣을게요." << endl;
                cout << "입력 : ";
                cin >> User_input;
                if (NumberChecker::IsNumeric(User_input)) {
                    int int_User_input = stoi(User_input);
                    myStack.push(int_User_input);
                    cout << j<< "번 째에 '" << int_User_input << "' 이 추가되었습니다.";
                }
                else {
                    cout << "숫자가 아닌 값을 입력하셨습니다." << endl;
                }
            }

            if (int_User_Choice == 2) {
                if (j == 0) {
                    cout << "현재 스택이 비어 제거할 수 없습니다." << endl;
                }
                if (j == 1 ) {
                    cout << "삭제 전 가장 마지막 스택인 " << j - 1 << "번 째에 있는 요소 '"; myStack.printLastElement(); cout << "' 을 제거했습니다." << endl;
                    myStack.pop();
                    cout << "이제 스택이 모두 비었습니다." << endl;
                    //cout << j - 1 << "번째 요소를 삭제했습니다." << endl;
                    //cout << "삭제 후 ";  myStack.printLastElement();
                }
                else {
                    cout << "삭제 전 가장 마지막 스택인 " << j - 1 << "번 째에 있는 요소 '"; myStack.printLastElement(); cout << "' 을 제거했습니다." << endl;
                    myStack.pop();
                    cout << "삭제 후 가장 마지막 스택인 " << j - 2 << "번 째에 있는 요소 '"; myStack.printLastElement(); cout << "' 입니다." << endl;
                }
                
            }

            if (int_User_Choice == 3) {
                if (j == 0) {
                    cout << "현재 스택이 비어 출력할 수 없습니다." << endl;
                }
                else {
                    cout << "맨 밑(bottom)부터 출력:" << endl;
                    myStack.printFromBottom();
                }
            }

            if (int_User_Choice == 4) {
                cout << "종료합니다." << endl;
                break;
            }

            if (int_User_Choice > 4 || int_User_Choice < 1) {
                cout << "잘못 입력하셨습니다. 1과 4사이의 숫자를 입력해주세요." << endl;
            }
            cout << "\n";
        }
        
        else {
            cout << "입력한 값은 숫자가 아닙니다. 1과 3의 사이의 숫자를 입력하세여" << endl;
        }
        cout << "\n";
    }

    return 0;
}
