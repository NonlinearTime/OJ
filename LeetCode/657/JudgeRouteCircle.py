class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        x = 0
        y = 0
        for item in moves:
            if item == 'U':
                y += 1
            if item == 'D':
                y -= 1
            if item == 'L':
                x -= 1
            if item == 'R':
                x += 1
        if x == 0 and y == 0:
            return True
        return False

