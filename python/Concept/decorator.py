# See https://openhome.cc/zh-tw/python/meta-programming/decorator/
def first(second):
    def wrapper(second):
        print('wrapper called')
        return second()
    
    print('first function called')
    
    return wrapper(second)

@first
def second():
    print('second function called')