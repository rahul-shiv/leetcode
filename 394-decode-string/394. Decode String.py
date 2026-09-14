class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        out = []
        for i in s:
            print(i,stack)
            if i.isdigit():
                if len(stack) and type(stack[-1]) == type('') :
                    stack[-1] +=i
                else:
                    stack.append(i)
            elif i == '[':
                stack.append([])
            elif i == ']':
                print(stack)
                x = stack[-1]*int(stack[-2])
                stack.pop()
                stack.pop()
                if len(stack):
                    stack[-1].extend(x)
                else:
                    stack.append(x)
            elif len(stack) and type(stack[-1])==type([]):
                stack[-1].append(i)
            else:
                stack.append(i)
            # print(stack)
            if not type(stack[0]) == type('') or not stack[0].isdigit():
                x = stack.pop()
                out.extend(x)
        print(out)
        return ''.join(out)