### 1. Найдем угол между медианой $AH$ и высотой $BD$, $\triangle$ с вершинами $A(4;2), B(2; -2), C(6;4)$:

1) **Медиана $AH$**: Соединяет вершину $A$ со средней точкой стороны $BC$.
   - **Средняя точка $H$ отрезка $BC$**:
     $$
     H\left(\frac{2 + 6}{2}, \frac{-2 + 4}{2}\right) = (4, 1)
     $$
   - **Направляющий вектор медианы $AH$**:
     $$
     \overrightarrow{AH} = (4 - 4, 1 - 2) = (0, -1)
     $$

2) **Высота $BD$**: Идет из вершины $B$ перпендикулярно стороне $AC$.
   - **Направляющий вектор стороны $AC$**:
     $$
     \overrightarrow{AC} = (6 - 4, 4 - 2) = (2, 2)
     $$
   - **Перпендикулярный вектор для высоты $BD$** — это вектор, ортогональный $\overrightarrow{AC}$, например, $(2, -2)$.

3) **Угол между векторами $\overrightarrow{AH}$ и $\overrightarrow{BD}$**:
     $$
     \cos \theta = \frac{\overrightarrow{AH} \cdot \overrightarrow{BD}}{\|\overrightarrow{AH}\| \cdot \|\overrightarrow{BD}\|}
     $$
   - **Скалярное произведение**:
     $$
     \overrightarrow{AH} \cdot \overrightarrow{BD} = (0)(2) + (-1)(-2) = 2
     $$
   - **Модули векторов**:
     $$
     \|\overrightarrow{AH}\| = \sqrt{0^2 + (-1)^2} = 1
     $$
     $$
     \|\overrightarrow{BD}\| = \sqrt{2^2 + (-2)^2} = \sqrt{8} = 2\sqrt{2}
     $$
   - **Косинус угла**:
     $$
     \cos \theta = \frac{2}{1 \cdot 2\sqrt{2}} = \frac{1}{\sqrt{2}} = \frac{\sqrt{2}}{2}
     $$
   - **Угол $\theta$**:
     $$
     \theta = 45^\circ
     $$

Итак, угол между медианой $AH$ и высотой $BD$ равен $45^\circ$.

### 2. Найдем точку пересечения медиан (центроид) треугольника $\triangle ABC$:

Центроид $G$ для треугольника определяется как среднее арифметическое координат его вершин:
$$
G\left( \frac{4 + 2 + 6}{3}, \frac{2 - 2 + 4}{3} \right)
$$
$$
G\left( \frac{12}{3}, \frac{4}{3} \right)
$$
$$
G(4, \frac{4}{3})
$$

Точка пересечения медиан треугольника $G$ находится в точке $\left( 4, \frac{4}{3} \right)$.

### 3. Напишем уравнение плоскости, проходящей через точку $M(1, 2, 3)$ и перпендикулярной к прямой $\alpha$:

$\alpha$ задана двумя уравнениями:

$$
\alpha:\begin{cases}
x + y + z = 0 \\
2x + 3y - 2z - 5 = 0
\end{cases}
$$

1) Нормальные векторы плоскостей:
   - Для первой плоскости $x + y + z = 0$ нормальный вектор $\mathbf{n_1} = (1, 1, 1)$.
   - Для второй плоскости $ 2x + 3y - 2z - 5 = 0 $ нормальный вектор $\mathbf{n_2} = (2, 3, -2)$.

2) Нормальный вектор искомой плоскости:
   Плоскость, перпендикулярная к прямой, заданной пересечением этих двух плоскостей, будет иметь нормальный вектор, который является вектором, перпендикулярным обоим нормальным векторам $\mathbf{n_1}$ и $\mathbf{n_2}$. Этот вектор можно найти с помощью векторного произведения:

   $
   \mathbf{n} = \mathbf{n_1} \times \mathbf{n_2}
   $

   Вычислим векторное произведение:

   $
   \mathbf{n} = \begin{vmatrix}
   \mathbf{i} & \mathbf{j} & \mathbf{k} \\
   1 & 1 & 1 \\
   2 & 3 & -2
   \end{vmatrix}
   $

   $
   \mathbf{n} = \mathbf{i} \begin{vmatrix}
   1 & 1 \\
   3 & -2
   \end{vmatrix} - \mathbf{j} \begin{vmatrix}
   1 & 1 \\
   2 & -2
   \end{vmatrix} + \mathbf{k} \begin{vmatrix}
   1 & 1 \\
   2 & 3
   \end{vmatrix}
   $

   $
   = \mathbf{i} (1 \cdot (-2) - 1 \cdot 3) - \mathbf{j} (1 \cdot (-2) - 1 \cdot 2) + \mathbf{k} (1 \cdot 3 - 1 \cdot 2)
   $

   $
   = -5\mathbf{i} + 4\mathbf{j} + 1\mathbf{k}
   $

   Таким образом, нормальный вектор плоскости $\mathbf{n} = (-5, 4, 1)$.

3) Уравнение плоскости:

   $
   -5(x - 1) + 4(y - 2) + 1(z - 3) = 0
   $

   Раскроем скобки:

   $
   -5x + 5 + 4y - 8 + z - 3 = 0
   $

   Упростим:

   $
   -5x + 4y + z - 6 = 0
   $

   Или в стандартной форме:

   $
   5x - 4y - z + 6 = 0
   $

### 4. решить систему ур-й:
$$
\begin{cases}x_1+2x_2+x_3-x_4=3 \\ x_1+x_2-x_3-x_4=2\end{cases}\\
x=\overline{x}+x
$$
