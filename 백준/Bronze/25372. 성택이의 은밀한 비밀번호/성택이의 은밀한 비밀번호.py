def solve(word: str) -> str:
    return 'yes' if len(word)>=6 and len(word)<=9 else 'no'

if __name__ == '__main__':
    n = int(input())

    for _ in range(n):
        word = input()

        print(solve(word))