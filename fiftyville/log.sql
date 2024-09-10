--
SELECT description FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2023;

SELECT transcript FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023;

SELECT activity, license_plate, minute
FROM bakery_security_logs
WHERE day = 28
AND month = 7
AND year = 2023
AND hour = 10;

SELECT id FROM flights
WHERE day = 29
AND month = 7
AND year = 2023
ORDER BY minute
LIMIT 1;

SELECT city FROM airports
JOIN flights
ON airports.id = flights.destination_airport_id
WHERE flights.id = 18;

SELECT caller, receiver
FROM phone_calls
WHERE day = 28
AND month = 7
AND year = 2023
AND duration 


SELECT account_number, transaction_type, amount
FROM atm_transactions
WHERE day = 28
AND month = 7
AND year = 2023;
