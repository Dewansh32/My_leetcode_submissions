# Write your MySQL query statement below
SELECT id
FROM (
    SELECT
        id,
        recordDate,
        temperature,
        LAG(temperature) OVER (
            ORDER BY recordDate
        ) AS previous_temperature,
        LAG(recordDate) OVER (
            ORDER BY recordDate
        ) AS previous_date
    FROM Weather
) AS w
WHERE temperature > previous_temperature
  AND previous_date = DATE_SUB(recordDate, INTERVAL 1 DAY);