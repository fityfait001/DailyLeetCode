# Write your MySQL query statement below
select e.name from
employee e
join employee sub
on e.id=sub.managerId
group by e.id , e.name
having count(sub.managerId)>=5;
