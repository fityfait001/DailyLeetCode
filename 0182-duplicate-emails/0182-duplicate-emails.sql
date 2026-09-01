# Write your MySQL query statement below
-- select email
-- from(
-- select email,
--     count(id) as occ
--     from person 
--     group by email)
--     where occ > 1

select email 
from person 
group by email
having count(id)>1