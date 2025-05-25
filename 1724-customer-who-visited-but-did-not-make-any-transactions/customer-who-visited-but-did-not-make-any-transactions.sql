# Write your MySQL query statement below
select customer_id, COUNT(customer_id) as count_no_trans
from visits a
left join transactions b on a.visit_id=b.visit_id
where transaction_id is null
group by customer_id;