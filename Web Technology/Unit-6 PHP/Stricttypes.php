<?php
declare(strict_types=1)?>
<?php

function add(int $a, int $b)
{
    return $a + $b; //a and b are of type int
}
function divide(int $x, int $y):float
{
    return $x/$y;
}
echo "the sum=" . add(5, 8);
echo"the quotient=" . divide(8, 5);
?>