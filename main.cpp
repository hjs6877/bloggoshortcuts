#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 1. 문자열 순회.
 * 2. shortcut 기호가 발견되었을때, '_'라면
 *  vector<start_shortcut, index>가 존재하지 않는다면 추가.
 *  존재 한다면 start_shortcut의 index 위치의 '_'를 '<i>'로, 현재 매치 된 '_'를 '</i>'로 교체.
 *  vector<start_shortcut,index>를 비운다.
 *
 * 3. 2번과 같은 방법으로, '*' 기호에 대해서 변환.
 */


class bloggoShortcuts {
public:
    string expand(string text){
        vector<int> underscoreV;
        vector<int> asteriskV;

        for(int i=0; i < text.size(); i++){
            if(text[i] == '_'){
                if(underscoreV.empty()){
                    underscoreV.push_back(i);
                }else{
                    const int& uVal = underscoreV.front();
                    text.erase(uVal,1);
                    text.insert(uVal, "<i>");

                    text.erase(i+2, 1);
                    text.insert(i+2, "</i>");

                    underscoreV.clear();
                }
            }else if(text[i] == '*'){
                if(asteriskV.empty()){
                    asteriskV.push_back(i);
                }else{
                    const int& aVal = asteriskV.front();
                    text.erase(aVal,1);
                    text.insert(aVal, "<b>");

                    text.erase(i+2, 1);
                    text.insert(i+2, "</b>");

                    asteriskV.clear();
                }
            }
        }
        return text;
    }
};

int main() {
    bloggoShortcuts bg;
    string text = bg.expand("_a_ _big_ *mouse* good **");

    cout << "result: " << text;
    return 0;
}