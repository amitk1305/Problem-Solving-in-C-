# Write your MySQL query statement below
SELECT 
    DISTINCT(p.product_id),
    IFNULL(ROUND(SUM(p.price * u.units) OVER w / SUM(u.units) OVER w, 2), 0) AS average_price
FROM  prices p 
LEFT JOIN unitssold u 
    ON p.product_id = u.product_id 
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
WINDOW w AS (PARTITION BY p.product_id);