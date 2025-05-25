# Write your MySQL query statement below
select DISTINCT(author_id) as id
from Views
where viewer_id = author_id
Order by author_id ASC;