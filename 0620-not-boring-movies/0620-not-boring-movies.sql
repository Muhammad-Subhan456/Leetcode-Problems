# Write your MySQL query statement below
SELECT * FROM CINEMA
WHERE MOD(ID,2)=1 AND description != 'boring'
ORDER BY rating DESC;