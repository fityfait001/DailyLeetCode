-- Input: 
-- Students table:
-- +------------+--------------+
-- | student_id | student_name |
-- +------------+--------------+
-- | 1          | Alice        |
-- | 2          | Bob          |
-- | 13         | John         |
-- | 6          | Alex         |
-- +------------+--------------+
-- Subjects table:
-- +--------------+
-- | subject_name |
-- +--------------+
-- | Math         |
-- | Physics      |
-- | Programming  |
-- +--------------+
select s.student_id,s.student_name,sb.subject_name,
ifnull(count(e.subject_name), 0) as attended_exams 
from students s 
cross join subjects sb
left join examinations e
on s.student_id=e.student_id
and e.subject_name=sb.subject_name
group by s.student_id,s.student_name,sb.subject_name
order by s.student_id,sb.subject_name;