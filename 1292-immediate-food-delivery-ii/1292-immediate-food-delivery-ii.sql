# Write your MySQL query statement below
select round(avg(case when x.cpfd = x.od then 1.0 else 0.0 end)*100,2)
as immediate_percentage from 
(Select customer_id, min(order_date) od,  min(customer_pref_delivery_date) cpfd
from Delivery group by customer_id) x