# Write your MySQL query statement below
SELECT M.NAME FROM EMPLOYEE E
JOIN EMPLOYEE M 
ON E.managerId = M.id
GROUP BY E.managerId
HAVING COUNT(*)>=5
