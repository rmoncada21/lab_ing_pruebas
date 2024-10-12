%% Parámetros de simulación
fs = 44100; % Frecuencia de muestreo
t = 0:1/fs:1-1/fs; % Vector de tiempo de 1 segundo
f = 1000; % Frecuencia de la señal sinusoidal
inputDigital = uint8(127 + 127*sin(2*pi*f*t)); % Señal digital de 8 bits

%% Parámetros del DAC0808
Vref = 5; % Voltaje de referencia
resolution = 8; % Resolución de 8 bits
maxDigitalValue = 2^resolution - 1;

%% Convertir señal digital a analógica
outputAnalog = (double(inputDigital) / maxDigitalValue) * Vref;

%% Añadir ruido y distorsión (simulación)
noiseLevel = 0.01; % Nivel de ruido
distortionLevel = 0.001; % Nivel de distorsión
outputAnalog_noise = outputAnalog + noiseLevel * randn(size(outputAnalog)); % Añadir ruido
outputAnalog = outputAnalog_noise + distortionLevel * sin(2*pi*3*f*t); % Añadir distorsión armónica

%% Añadir ruido y distorsión (simulación)
noiseLevel = 0.01; % Nivel de ruido
distortionLevel = 0.001; % Nivel de distorsión
outputAnalog = outputAnalog + noiseLevel * randn(size(outputAnalog)); % Añadir ruido
outputAnalog = outputAnalog + distortionLevel * sin(2*pi*3*f*t); % Añadir distorsión armónica

%% Visualizar la señal
figure;
plot(t, outputAnalog_noise);
h = findobj(gca, 'Type', 'line');
% Grosor de la línea
set(h, 'LineWidth', 3);
title('Señal Analógica Simulada con ruido');
xlabel('Tiempo (s)', 'FontSize', 16);
ylabel('Voltaje (V)', 'FontSize', 16);
set(gca, 'FontSize', 40); 
grid on;

figure;
plot(t, outputAnalog);
h = findobj(gca, 'Type', 'line');
% Grosor de la línea
set(h, 'LineWidth', 3);
title('Señal Analógica Simulada Tono');
xlabel('Tiempo (s)', 'FontSize', 16);
ylabel('Voltaje (V)', 'FontSize', 16);
set(gca, 'FontSize', 40); 
grid on;


%% Calculos de distorsión
% Calcular THD
thdValue = thd(outputAnalog, fs);

% Calcular SINAD
sinadValue = sinad(outputAnalog, fs);

% Calcular SNR
snrValue = snr(outputAnalog, fs);

% Mostrar resultados
fprintf('THD: %f dB\n', thdValue);
fprintf('SINAD: %f dB\n', sinadValue);
fprintf('SNR: %f dB\n', snrValue);

% Calcular THD+N (Distorsión Total + Ruido)
signalPower = bandpower(outputAnalog, fs, [0, fs/2]); % Potencia total de la señal
fundamentalPower = bandpower(outputAnalog, fs, [f-5, f+5]); % Potencia de la señal fundamental
noiseAndDistortionPower = signalPower - fundamentalPower; % Potencia de ruido y distorsión

thdNValue = 10 * log10(noiseAndDistortionPower / signalPower) * 100; % THD+N en porcentaje

% Mostrar THD+N
fprintf('THD+N: %f%%\n', thdNValue);
