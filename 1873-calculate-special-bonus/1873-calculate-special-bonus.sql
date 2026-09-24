# Write your MySQL query statement below
-- select employee_id,
-- case
--     when employee_id%2=0 or name like "M%" then 0
--     else salary
--     end as bonus
-- from employees
-- order by employee_id;


select employee_id , 
case
    when employee_id%2=0 OR NAME LIKE 'M%' THEN 0
    ELSE SALARY

    END AS BONUS
FROM EMPLOYEES
ORDER BY EMPLOYEE_ID;