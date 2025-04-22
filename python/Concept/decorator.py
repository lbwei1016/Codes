# See https://openhome.cc/zh-tw/python/meta-programming/decorator/

"""
The return value of `first` in the below implementation is `None`, 
and thus after calling the decorator `first(second)`, `second` is assigned
with `None`, which is not callable.
"""
# def first(second):
#     def wrapper(second):
#         print('wrapper called')
#         return second()
    
#     print('first function called')
    
#     return wrapper(second)

"""
The below implementation only calls `first()` initially.
The wrapper and the `second` function are called when
`second()` is explicitly executed.
"""
def first(second):
    """First function"""
    def wrapper():
        """Wrapper"""
        print('wrapper called')
        return second()
    
    print('first function called')
    
    return wrapper

"""
This "decorator on a function", is essentially:
    second = first(second)
"""
@first
def second():
    print('second function called')


if __name__ == "__main__":
    print(second.__doc__)
    second()