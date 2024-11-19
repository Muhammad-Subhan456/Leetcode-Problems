# Write your MySQL query statement below
SELECT P.PRODUCT_NAME,S.YEAR,S.PRICE FROM SALES S
LEFT JOIN PRODUCT P ON S.product_id = P.product_id 