#make fibgened
def fib(n):
    if(n <= 2):
        return 1
    if(n >= 4):
        return fib(n-1) + fib(n-2)-fib(n-4)+fib(n-3)
    return fib(n-1) + fib(n-2)

def main():
    for i in range(1,11):
        print(fib(i))

if __name__ == "__main__":
    main()

