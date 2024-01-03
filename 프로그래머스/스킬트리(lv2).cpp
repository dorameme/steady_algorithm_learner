/*
start:16:10
end:16:28
시간복잡도:O(N)
공간복잡도:O(N)
풀아:각 스킬마다 선수가 되는 스킬을 저장해준다 !
*/
#include <string>
#include <vector>

using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector <char> v[400];
    for(int i=0;i<skill.size();i++){
        for(int j=0;j<i;j++){
            v[skill[i]].push_back(skill[j]);//skill[i]를 위해 필요한 요소
        }
    }
    
    for(int i=0;i<skill_trees.size();i++){
        int ableToDo[400]={0,};
        int flag=0;
        for(int j=0;j<skill_trees[i].size();j++){//문자열 하나 꺼내
            for(int z=0;z<v[skill_trees[i][j]].size();z++){
                if(ableToDo[v[skill_trees[i][j]][z]])
                    continue;
                else{
                    flag=1; 
                    break;
                }
            }//선수스킬이 다되는지 확인
            if(flag==0){
                ableToDo[skill_trees[i][j]]=1;
            }
            else{break;}
        }
        if(flag==0)answer++;
    }
    return answer;
}
