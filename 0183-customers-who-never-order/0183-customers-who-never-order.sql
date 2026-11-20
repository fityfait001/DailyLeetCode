# Write your MySQL query statement below
select  name as Customers from customers c  where not exists(
select 1 from orders o where 
o.customerId = c.id
);