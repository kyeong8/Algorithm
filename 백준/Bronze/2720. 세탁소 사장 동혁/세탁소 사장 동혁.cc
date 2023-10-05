#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, C;
    int Q, D, N, P;

    //freopen("input.txt", "r", stdin);
    cin >> T;
    

    for (int i = 0; i < T; i++)
    {
        Q, D, N, P = 0;

        cin >> C;
        
        Q = C / 25;
        C = C % 25;
        
        D = C / 10;
        C = C % 10;

        N = C / 5;
        C = C % 5;

        P = C;

        cout << Q << " " << D << " " << N << " " << P << "\n";
    }

    return 0;
}