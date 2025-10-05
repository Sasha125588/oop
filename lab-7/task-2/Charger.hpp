#pragma once

enum ConnectorType {
    USB_C,
    MICRO_USB
};

class Charger {
    private:
    ConnectorType connectorType;
    int outputPower;

    public:
    Charger(ConnectorType connectorType, int outputPower)
        : connectorType(connectorType), outputPower(outputPower) {}

    ConnectorType getConnectorType() { return connectorType; }
    void setConnectorType(ConnectorType connectorType) {
        this->connectorType = connectorType;
    }

    int getOutputPower() { return outputPower; }
    void setOutputPower(int outputPower) {
        this->outputPower = outputPower;
    }
};