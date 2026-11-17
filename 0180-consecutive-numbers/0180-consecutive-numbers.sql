# Write your MySQL query statement below
-- select distinct l1.num as ConsecutiveNums
-- from Logs l1 join
-- Logs l2 on l1.id+1=l2.id
-- join Logs l3 on
-- l2.id+1=l3.id
-- where l1.num=l2.num and
-- l2.num=l3.num 

with ans AS (
    select id,
    num,
    LAG(num) over (order by id) as prev_num,
    LEAD(num) over(order by id) as next_num

    from logs
)
select distinct num as ConsecutiveNums
from ans
where num=prev_num
and num=next_num