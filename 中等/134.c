int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0, currentGas = 0, start = 0;
    for (int i = 0; i < gasSize; i++) {
        totalGas += gas[i] - cost[i];
        currentGas += gas[i] - cost[i];
    
        if (currentGas < 0) {
            start = i + 1;  
            currentGas = 0; // 重置当前汽油量
        }
    }
    // 如果总汽油为正数，则存在解
    return totalGas >= 0 ? start : -1;
}
