# Write your MySQL query statement below
SELECT S.user_id,round(ifnull(avg(action = 'confirmed'), 0),2) as confirmation_rate
FROM SIGNUPS S
LEFT JOIN CONFIRMATIONS C ON S.user_id = C.user_id
GROUP BY S.user_id