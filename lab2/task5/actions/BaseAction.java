package task5.actions;


import task5.NumberSequence;

public abstract class BaseAction {
    protected NumberSequence source;

    public BaseAction(NumberSequence source) {
        this.source = source;
        source.attach(this);
    }

    public void setSource(NumberSequence source) {
        if (this.source != null) {
            this.source.dettach(this);
        }
        this.source = source;
    }

    public abstract void update();
}
