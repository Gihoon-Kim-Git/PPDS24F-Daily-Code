class ExamRoom(object):
   def __init__(self, n):
       self.n = n
       self.students = []

   def seat(self):
       if not self.students:
           self.students.append(0)
           return 0
           
       dist = max_seat = 0
       
       if self.students[0] != 0:
           dist = self.students[0]
           max_seat = 0
           
       for i in range(len(self.students) - 1):
           curr_dist = (self.students[i + 1] - self.students[i]) // 2
           if curr_dist > dist:
               dist = curr_dist
               max_seat = self.students[i] + dist
               
       if self.students[-1] != self.n - 1:
           curr_dist = self.n - 1 - self.students[-1]
           if curr_dist > dist:
               max_seat = self.n - 1
               
       idx = 0
       while idx < len(self.students) and self.students[idx] < max_seat:
           idx += 1
       self.students.insert(idx, max_seat)
       
       return max_seat

   def leave(self, p):
       self.students.remove(p)