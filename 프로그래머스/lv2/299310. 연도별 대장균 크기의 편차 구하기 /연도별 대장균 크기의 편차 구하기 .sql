-- 코드를 작성해주세요
select year(differentiation_date) year,
    (select max(size_of_colony)
    from ecoli_data
    where year(differentiation_date) = year)
    - size_of_colony year_dev,
    id
from ecoli_data
order by year, year_dev