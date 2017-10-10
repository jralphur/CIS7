class Tower():
  def __init__(self, name, stack):
    self.name = name;
    self.stack = stack[:]

A, B, C = Tower('A', []), Tower('B', []), Tower('C', [])

rings = input("How many rings do you want?");
A.stack = [i for i in range(int(rings), 0, -1)];

def stacklog():
  print("Tower {0}: {1}". format(A.name, A.stack))
  print("Tower {0}: {1}". format(B.name, B.stack))
  print("Tower {0}: {1}". format(C.name, C.stack))

def move(n, start, end, spare):
  if n > 0:
    move(n - 1, start, spare, end);
    popped = start.stack.pop();
    end.stack.append(popped)
    stacklog();
    print("Moved {0} from {1} to {2}".format(popped, start.name, end.name))
    move(n - 1, spare, end, start);

move(int(rings), A, C, B);
