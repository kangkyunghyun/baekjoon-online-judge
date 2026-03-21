-- 코드를 작성해주세요
select i.id, n.fish_name, i.length
from fish_info i, fish_name_info n
where i.fish_type = n.fish_type
and i.length = (select max(length)
               from fish_info
               where fish_type = i.fish_type)
order by id