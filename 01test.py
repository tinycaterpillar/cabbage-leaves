import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# 벡터 필드 정의
def vector_field(x, y):
    dx_dt = -0.1 * x**3 + 2 * y**3
    dy_dt = -2 * x**3 - 0.1 * y**3
    return dx_dt, dy_dt

# ODE 시스템 정의
def ode_system(t, z):
    x, y = z
    dx_dt, dy_dt = vector_field(x, y)
    return [dx_dt, dy_dt]

# Slope Field 그리드 생성
x = np.linspace(-2, 2, 20)  # x 범위
y = np.linspace(-2, 2, 20)  # y 범위
X, Y = np.meshgrid(x, y)    # 그리드 생성
DX, DY = vector_field(X, Y) # 벡터 계산

# 벡터 크기 정규화 (보기 좋게 조정)
magnitude = np.sqrt(DX**2 + DY**2)
DX /= magnitude*10
DY /= magnitude*10

# Slope Field 시각화
plt.figure(figsize=(10, 8))
plt.quiver(X, Y, DX, DY, angles="xy", scale_units="xy", scale=0.5, color="gray", alpha=0.7)

# Trajectory 계산 및 시각화
ic = [2, 0]  # 초기 조건
t_span = (0, 10)  # 시간 범위
t_eval = np.linspace(0, 10, 1000)  # 시간 샘플링

sol = solve_ivp(ode_system, t_span, ic, t_eval=t_eval)
plt.plot(sol.y[0], sol.y[1], label=f"Trajectory", color='green')
plt.plot(ic[0], ic[1], 'r*', label=f"initial condition: ({ic[0]}, {ic[1]})", markersize=20)

# 그래프 설정
plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("Vector Field of the System")
plt.axhline(0, color="black", linewidth=0.5, linestyle="--")
plt.axvline(0, color="black", linewidth=0.5, linestyle="--")
plt.legend()
plt.grid()
plt.show()
