# Write your MySQL query statement below
#1)Find those visit_ids who have made a transaction
#2)Get those customers who haven't made a transaction
select customer_id
       , count(visit_id) as count_no_trans
from ( select *
    from visits
    where visit_id not in (select distinct visit_id
                        from transactions)
    ) as cust_no_trans 
group by customer_id

